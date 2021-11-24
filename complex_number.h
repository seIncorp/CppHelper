
class COMPLEXNUMBER
{
public:
	double re1;
	double im1;

	typedef struct {
		double radius;
		double phase;
	} RADIUS_PHASE_DATA;

	COMPLEXNUMBER(double re = 0.0, double im = 0.0)
	{
		re1 = re;
		im1 = im;
	}

	COMPLEXNUMBER* add(COMPLEXNUMBER addend)
	{
		return new COMPLEXNUMBER((re1 + addend.re1), (im1 + addend.im1));
	}

	COMPLEXNUMBER* subtract(COMPLEXNUMBER sub)
	{
		return new COMPLEXNUMBER((re1 - sub.re1), (im1 - sub.im1));
	}

	COMPLEXNUMBER* multiply(COMPLEXNUMBER multiplicand)
	{
		return new COMPLEXNUMBER((re1 * multiplicand.re1 - im1 * multiplicand.im1), (re1 * multiplicand.im1 + im1 * multiplicand.re1));
	}

	COMPLEXNUMBER* divide(COMPLEXNUMBER divider)
	{
		COMPLEXNUMBER* dividerConjugate = conjugate(divider);

		COMPLEXNUMBER* finalDivident = multiply(*dividerConjugate);

		double finalDivider = pow(divider.re1, 2) + pow(divider.im1, 2);

		return new COMPLEXNUMBER(finalDivident->re1 / finalDivider, finalDivident->im1 / finalDivider);
	}

	COMPLEXNUMBER* conjugate(COMPLEXNUMBER number)
	{
		return new COMPLEXNUMBER(number.re1, (-1 * number.im1));
	}

	double getRadius()
	{
		return sqrt(pow(re1, 2) + pow(im1, 2));
	}

	double getPhase(bool inRadians = true)
	{
		double phase = atan(abs(im1) / abs(re1));

		if (re1 < 0 && im1 > 0)
		{
			phase = M_PI - phase;
		}
		else if (re1 < 0 && im1 < 0)
		{
			phase = -(M_PI - phase);
		}
		else if (re1 > 0 && im1 < 0)
		{
			phase = -phase;
		}
		else if (re1 == 0 && im1 > 0)
		{
			phase = M_PI / 2;
		}
		else if (re1 == 0 && im1 < 0)
		{
			phase = -M_PI / 2;
		}
		else if (re1 < 0 && im1 == 0)
		{
			phase = M_PI;
		}
		else if (re1 > 0 && im1 == 0)
		{
			phase = 0;
		}
		else if (re1 == 0 && im1 == 0)
		{
			phase = 0;
		}

		if (!inRadians)
		{
			phase = RADIAN_TO_DEGREE(phase);
		}

		return phase;
	}

	RADIUS_PHASE_DATA* getPolarForm(bool inRadians = true)
	{
		RADIUS_PHASE_DATA temp = { getRadius(), getPhase(inRadians) };

		return &temp;
	}
};