

/*Factorial*/
// TODO: recursive with function
#define FACTORIAL(_n_) ({ \
	int _res_ = 1; \
	int _i_ = 2; \
	while(_i_ <= (_n_) ) \
	{ \
		_res_ *= _i_; \
		_i_++; \
	} \
	_res_; \
})

/*fibonacci*/
// return whole array of every step
#define FIBONACCI(_n_) ({ \
	std::vector<int> _a_ ; \
	int _c_ = 1; \
	int _p_ = 0; \
	 \
	if(_n_ == 1)  \
	{ \
	 _a_.push_back(1); \
	} \
	else \
	{ \
		int _i_ = _n_ - 1; \
		_a_.push_back(1); \
		while (_i_) \
		{ \
			_c_ += _p_; \
			_p_ = _c_ - _p_; \
			_a_.push_back(_c_); \
			_i_--; \
		} \
	} \
	_a_; \
})

// return only the last step
#define FIBONACCINth(_n_) ({ \
	int _c_ = 1; \
	int _p_ = 0; \
	if (_n_ == 1)  \
	{ \
		_c_ = 1; \
	} \
	else \
	{ \
		int _i_ = _n_ - 1; \
		while (_i_)  \
		{ \
			_c_ += _p_; \
			_p_ = _c_ - _p_; \
			_i_--; \
		} \	
	} \
	_c_; \
})

#define FIBONACCIClosedForm(_n_) ({ \
	int _tmp_ = 70; \
	int _res_ = 0; \
	if (_n_ < 1 || _n_ > _tmp_) { \
		er << "Can't handle position smaller than 1 or greater than ${topMaxValidPosition}"; \
	} \
	double _sqrt5_ = sqrt(5); \
	double _phi_ = (1 + _sqrt5_) / 2; \
	_res_ = floor(( pow(_phi_, _n_) ) / _sqrt5_ + 0.5); \
	_res_; \
})

#define PRIME_FACTORS(_n_) ({ \
	std::vector<int> _res_; \
	int _t_ = (_n_); \
	for(int f = 2; f <= sqrt(_t_); f++) \
	{ \
		while (_t_ % f == 0) \
		{ \
			_t_ /= f; \
			_res_.push_back(f); \
		} \
	} \
	if (_t_ != 1)  \
	{ \
		_res_.push_back(_t_); \
	} \
	_res_; \
})

// ??
#define HARDYRAMANUJAN_MACRO(_n_) ({ \
	int _res_ = log(log(_n_)); \
	_res_; \
})

#define PRIMALITY_TEST_v1(_n_) ({ \
	bool _res_ = true; \
	 \
	if (_n_ == 2 || _n_ == 3) \
	{ \
        _res_ = true; \
	} \
	else if (_n_ <= 1 || _n_ % 2 == 0 || _n_ % 3 == 0) \
	{ \
        _res_ = false; \
	} \
	else \
	{ \
		for (int _i_ = 5; _i_ * _i_ <= _n_; _i_ += 6) \
		{ \
			if (_n_ % _i_ == 0 || _n_ % (_i_ + 2) == 0) \
				_res_ = false; \
		} \
	} \
	_res_; \
})

// TODO: https://github.com/trekhleb/javascript-algorithms/blob/master/src/algorithms/math/primality-test/trialDivision.js
#define PRIMALITY_TEST_v2(_n_) ({})

// TODO: recursive version
#define EUCLIDEANALGORITHMITERATIVE(_oa_, _ob_) ({ \
	int _res_ = 0; \
	int _a_ = abs(_oa_); \
	int _b_ = abs(_ob_); \
	 \
	while(_a_ && _b_ && _a_ != _b_) \
	{ \
		if(_a_ > _b_) \
		{ \
			_a_ = _a_ - _b_; \
		} \
		else \
		{ \
			_b_ = _b_ - _a_; \
		} \
	} \
 \
	if(_a_ != 0) \
		_res_ = _a_; \
	else \
		_res_ = _b_; \
	_res_;	 \
})

#define LEASTCOMMONMULTIPLE(_n1_, _n2_) ({ \
	int _r_ = 0; \
	if((_n1_ == 0) || (_n2_ == 0)) \
	{ \
		_r_ = 0; \
	} \
	else \
	{ \
		_r_ = ( abs(_n1_ * _n2_) / EUCLIDEANALGORITHMITERATIVE(_n1_, _n2_) ); \
	} \
	_r_; \
})

#define SIEVE_OF_ERATOSTHENES(_n_) ({ \
	std::vector<bool> _ip_; \
	_ip_.assign( (_n_ + 1), true ); \
	_ip_[0] = false; \
	_ip_[1] = false; \
	std::vector<int> _p_; \
	\
	for(int _nu_ = 2; _nu_ <= _n_; _nu_ += 1)  \
	{ \
		if (_ip_[_nu_] == true) \
		{ \
			_p_.push_back(_nu_); \
			int _nn_ = _nu_ * _nu_; \
			\
			while (_nn_ <= _n_) \
			{ \
				_ip_[_nn_] = false; \
				_nn_ += _nu_; \
			} \
		} \
	} \
	_p_; \
})

#define IS_POWER_OF_TWO_BITWISE(_n_) ({ \
	bool _res_ = true; \
	if (_n_ < 1) \
	{ \
		_res_ = false; \
	} \
	else \
	{ \
		_res_ = (_n_ & (_n_ - 1)) == 0; \
	} \
	_res_; \
})

#define IS_POWER_OF_TWO(_n_) ({ \
	bool _res_ = true; \
	if (_n_ < 1)  \
	{ \
		_res_ = false; \
	} \
	int _dn_ = _n_; \
	while (_dn_ != 1) \
	{ \
		if (_dn_ % 2 != 0) \
		{ \
			_res_ = false; \
		} \
		_dn_ /= 2; \
	} \
	_res_;  \
})

// TODO: recursive version
#define PASCAL_TRIANGLE(_n_,_arr_) ({ \
	for(int _l_ = 0; _l_ < _n_; _l_++) \
		for(int _i_ = 0; _i_ < _n_; _i_++) \
			(_arr_)[_l_][_i_] = 0; \
	 \
	for(int _l_ = 0; _l_ < _n_; _l_++) \
	{ \
		for(int _i_ = 0; _i_ <= _l_; _i_++) \
		{ \
			if (_l_ == _i_ || _i_ == 0) \
				(_arr_)[_l_][_i_] = 1; \
			else \
				(_arr_)[_l_][_i_] = (_arr_)[_l_-1][_i_-1] + (_arr_)[_l_-1][_i_]; \
			printf("%d ", (_arr_)[_l_][_i_]); \
		} \
		printf("\n"); \
	} \
})

#define DEGREE_TO_RADIAN(_degree_) ({ \
	double _r_ = _degree_ * (M_PI / 180); \
	_r_; \
})

#define RADIAN_TO_DEGREE(_radian_) ({ \
	double _r_ = _radian_ * (180 / M_PI); \
	_r_; \
})

// TODO: recursive style
#define FAST_POWERING(_x_, _n_) ({ \
	int _x1_ = _x_; \
	int _n1_ = _n_; \
	int _ret_ = 0; \
	if( _n_ < 0 ) \
	{ \
		_x1_ = 1 / _x1_; \
		_n1_ = -_n1_; \
	} \
	\
	if( _n1_ == 0 ) \
	{ \
		_ret_ = 1; \
	} \
	else \
	{ \
		int _y_ = 1; \
		while( _n1_ > 1 ) \
		{ \
			if( IS_EVEN(_n1_) == 1 ) \
			{  \
				_x1_ = _x1_ * _x1_; \
				_n1_ = _n1_ / 2; \
			} \
			else \
			{ \
				_y_ = _x1_ * _y_; \
				_x1_ = _x1_ * _x1_; \
				_n1_ = ((_n1_ - 1) / 2); \
			} \
		} \
		_ret_ = _x1_ * _y_; \
	} \
	_ret_; \
})

#define HORNER_METHOD(_coefficients_, _len_,_xVal_) ({ \
	int *_arr_ = _coefficients_; \
	int _res_ = 0; \
	 \
	for(int _a_ = 0; _a_ < _len_; _a_++) \
	{ \
		_res_ = _res_ * _xVal_ + (*(_arr_ + _a_)); \
	} \
	_res_; \
})

#define CLASSIC_POLYNOME(_coefficients_, _len_, _xVal_) ({ \
	int *_arr_ = _coefficients_; \
	int _res_ = 0; \
	 \
	for(int _a_ = 0; _a_ < (_len_); _a_++) \
	{ \
		_res_ = _res_ + (*(_arr_ + _a_)) * pow(_xVal_, (  (_len_-1) - _a_  )); \
	} \
	_res_; \
})




















#include "complex_number.h"




