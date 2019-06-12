class PassRegistry {
public:
  static PassRegistry *getPassRegistry();
};

static PassRegistry PassRegistryObj;

PassRegistry *PassRegistry::getPassRegistry() {
  return &PassRegistryObj;
}

int main() { } 
