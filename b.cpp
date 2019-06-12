#include<functional>
#include<mutex>

#define LLVM_EXTERNAL_VISIBILITY __attribute__ ((visibility("default")))

class PassRegistry {
public:
  static PassRegistry *getPassRegistry();
};

void initializeFooPass(PassRegistry &);

static void *initializeFooPassOnce(PassRegistry &Registry) {
  return nullptr;
}
static std::once_flag InitializeFooPassFlag;

void initializeFooPass(PassRegistry &Registry) {
  std::call_once(InitializeFooPassFlag,
                  initializeFooPassOnce, std::ref(Registry));
}
