typedef struct node* FloatStack;

FloatStack start_stk();
int stack_empty(FloatStack);
int stack_push(FloatStack*, float value);
int stack_pop(FloatStack*, float *value);
int stack_top(FloatStack*, float *value);
int free_stack(FloatStack*);