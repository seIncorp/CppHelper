

/* Top-down implementation */
void top_down_merge_sort(int a_arr[], int b_arr[], int len);
void top_down_split_and_merge(int b_arr[], int begin, int end, int a_arr[]);
void top_down_merge(int a_arr[], int begin, int middle, int end, int b_arr[]);


/* Bottom-up implementation */
void bottom_up_merge_sort(int a_arr[], int b_arr[], int len);
void bottom_up_merge(int a_arr[], int left, int right, int end, int b_arr[]);

