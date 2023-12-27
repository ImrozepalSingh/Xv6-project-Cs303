#define T_DIR  1   // Directory
#define T_FILE 2   // File
#define T_DEV  3   // Device

struct stat {
  short type;  // Type of file
  int dev;     // File system's disk device
  uint ino;    // Inode number
  short nlink; // Number of links to file
  uint size;   // Size of file in bytes
};


enum U_procstate { U_UNUSED, U_EMBRYO, U_SLEEPING, U_RUNNABLE, U_RUNNING, U_ZOMBIE };

// Per-process state
struct uproc {
  uint sz;                     // Size of process memory (bytes)
  pde_t* pgdir;                // Page table
  char *kstack;                // Bottom of kernel stack for this process
  enum U_procstate state;        // Process state
  int pid;                     // Process ID
  int ppid;         // Parent process
  struct trapframe *tf;        // Trap frame for current syscall
  struct context *context;     // swtch() here to run process
  void *chan;                  // If non-zero, sleeping on chan
  int killed;                  // If non-zero, have been killed
 
 
  char name[16];               // Process name (debugging)
};
