# lua中进行函数调用时栈的状态
---一个总的数据栈：每个lua环境唯一的栈，所有的调用信息都存在这上面。

```cpp
struct lua_State {
  CommonHeader;
  lu_byte status;
  StkId top;  /* first free slot in the stack */
  StkId base;  /* base of current function */
  global_State *l_G;
  CallInfo *ci;  /* call info for current function */
  const Instruction *savedpc;  /* `savedpc' of current function */
  StkId stack_last;  /* last free slot in the stack */
  StkId stack;  /* stack base */
  CallInfo *end_ci;  /* points after end of ci array*/
  CallInfo *base_ci;  /* array of CallInfo's */
  int stacksize;
  int size_ci;  /* size of array `base_ci' */
  unsigned short nCcalls;  /* number of nested C calls */
  lu_byte hookmask;
  lu_byte allowhook;
  int basehookcount;
  int hookcount;
  lua_Hook hook;
  TValue l_gt;  /* table of globals */
  TValue env;  /* temporary place for environments */
  GCObject *openupval;  /* list of open upvalues in this stack */
  GCObject *gclist;
  struct lua_longjmp *errorJmp;  /* current error recover point */
  ptrdiff_t errfunc;  /* current error handling function (stack index) */
};
```
*****************************************************************************************
**stack**:lua栈的实体，在每个lua环境中是唯一的，每个函数的调用栈只是stack上的一小段。  
**top、base**：指向当前调用栈的栈顶和栈底。
**ci**:当前函数的调用信息，具体结构如下所示函数调用栈所示。
**base_ci**：函数调用信息的列表，用来记录和恢复当前的调用信息。
*****************************************************************************************

---函数调用栈。并不是一个独立的栈，只是数据段上的一小段。
```cpp
typedef struct CallInfo {
  StkId base;  /* base for this function */
  StkId func;  /* function index in the stack */
  StkId	top;  /* top for this function */
  const Instruction *savedpc;
  int nresults;  /* expected number of results from this function */
  int tailcalls;  /* number of tail calls lost under this entry */
} CallInfo;
```
**************************************************************************
**base**:当前调用栈的栈底。
**top**:当前调用栈的栈顶。
**func**:当前调用的函数在stack中的位置。
**nresults**:当前函数预期会返回的结果数，如果返回的数量不够，会用nil补齐。
****************************