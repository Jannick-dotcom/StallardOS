## **Stallardo Operating System**
**StallardOS_SVC**

StallardOS supports syscalls (service calls), to allow privileged access out of unprivileged tasks.
Therfore a convention was defined
_________________________________________________________________________________________

### Calling the SVC
All SVCs are called by using preprocessor macros, which help abstracting assembly calls to C/C++.
These method abide the naming convention `CALL_xxx`.
> `CALL_PENDSV();`

The macro expands to a single assembly instruction
`SVC #x`, where x is the number of the requested syscall, defined as `SV_XXX`.

The method does **not** check if the caller is privileged or unprivileged. Calls from privileged tasks
will result in an SVC aswell, causing unneseccary overhead.

#### __Calling Restrictions__
There's no calling restrictions in place. All unprivileged tasks are allowed to execute any implemented SVC

_________________________________________________________________________________________

### Handling the SVC

Hall SVCs are calling the assigned interrupt handler
> `void SVC_Handler()`

The handler is currently in `StallardOSContextSwitch.c` but might be moved into a separate file in the future.

The handler gets the SVC number and executes the corresponding method (e.g. `pendPendSV()` for `SV_PENDSV`).

_________________________________________________________________________________________

### Executing the SVC

SVC functionality is currently implented in the same file as the handler, but might be moved aswell.
The implementation methods perform the requested action, like accessing control registers.

_________________________________________________________________________________________

### Privileged Shortcut

Privileged tasks may call the implementation methods directly, to not cause unnecessary overhead.
At the moment, the implementation functions are not exposed to the StallardOS-class, so a re-implementation might be necessary.

_________________________________________________________________________________________

### Privilege Detection

There's currently no helper methods to detect the privilege state of a task.
This is not reqired atm, as all tasks run in unprivileged mode