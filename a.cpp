#include<functional>
#include<mutex>

#define LLVM_EXTERNAL_VISIBILITY __attribute__ ((visibility("default")))

class PassRegistry {
public:
  static PassRegistry *getPassRegistry();
};

void initializeX86ExecutionDomainFixPass(PassRegistry &);

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeX86Target() {
  PassRegistry &PR = *PassRegistry::getPassRegistry();
  initializeX86ExecutionDomainFixPass(PR);
}

static void *initializeX86ExecutionDomainFixPassOnce(PassRegistry &Registry) {
  return nullptr;
}
static std::once_flag InitializeX86ExecutionDomainFixPassFlag;

void initializeX86ExecutionDomainFixPass(PassRegistry &Registry) {
  std::call_once(InitializeX86ExecutionDomainFixPassFlag,
                  initializeX86ExecutionDomainFixPassOnce, std::ref(Registry));
}
