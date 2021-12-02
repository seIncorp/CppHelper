

/*Brute Force*/
#define LINEAR_SEARCH(_x_, _len_, _v_) ({ \   
int* _a_ = (_x_); \
int _c_ = 0; \
int _res_ = 0; \
while (_c_ < (_len_)) \
{ \
if (*(_a_ + _c_) == _v_) {/*printf("%d ",*(a+c) );*/ _res_ = _c_; } _c_++; \
} \
_res_; \
})