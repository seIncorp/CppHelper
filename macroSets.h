
void fisherYates(int originalArray[], int len_original, int res[]);

#define FISHER_YATES_MACRO( _originalArray_, _len_original_, _res_) ({ \
    int *_oa_ = _originalArray_; \
    int *_rr_ = _res_; \
     \
    for(int _aa_ = 0; _aa_ < _len_original_; _aa_++) \
        *(_rr_ + _aa_) = *(_oa_ + _aa_); \
         \
    for (int _i_ = (_len_original_ - 1); _i_ > 0; _i_ -= 1)  \
    { \
        int _randomIndex_ = floor(rand() % (_i_ + 1)); \
 \
        int temp = *(_rr_ + _i_); \
        *(_rr_ + _i_) = *(_rr_ + _randomIndex_); \
        *(_rr_  + _randomIndex_) = temp; \
    } \
})




void power_set(int os[], int len);

#define POWER_SET_MACRO(_os_,_len_,_r_) ({ \
    int *_a_ = _os_; \
    std::vector<std::vector<int>> *_ret_ = (_r_); \
    int _noc_ = pow(2, _len_); \
     \
    for(int _ci_ = 0; _ci_ < _noc_; _ci_++) \
    { \
        std::vector<int> _temp_; \
        for (int _si_ = 0; _si_ < _len_; _si_++)  \
        { \
            if (_ci_ & (1 << _si_))  \
            { \
            _temp_.push_back( *(_a_+_si_) ); \
            o << "** " << *(_a_+_si_) << " "; \
            } \
        } \
        ee; \
        _ret_->push_back(_temp_); \
    } \
})



//          array[a][b][c]
//          for(i) -> for(j) -> for(x)
//          array[ i * (b * c) + j * (c) + x  ] = ...;
#define OFFSET_3D_ARRAY_ONE_POINTER(_a_,_b_,_c_,_i_,_j_,_x_) ({ \
     int _r_ = _i_ * (_b_ * _c_) + _j_ * (_c_) + _x_; \
     _r_; \
})

int cartesianProduct(int a[], int a_len, int b_len, int b[], int* ret);




#include "combinations.h"


string longest_common_subsequence(string set1, int set1_len, string set2, int set2_len);



int longest_increasing_subsequence_length(int X[], int len);
int* longest_increasing_subsequence(int X[], int len);


#include "knap_sack.h"



