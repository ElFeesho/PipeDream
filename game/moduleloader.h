
#ifndef __MODULE_LOADER_H__
#define __MODULE_LOADER_H__

#include <string>
#include <dlfcn.h>

using namespace std;

class ModuleLoaderException
{
public:
	ModuleLoaderException(const string &error) : errorReason(error) {}
	string getErrorReason() { return errorReason; }
private:
	string errorReason;
};

template<class RetType> class ModuleLoader
{
public:

	ModuleLoader(const string &module, const string &symbol) : modulePath(module), symbolToLoad(symbol)
	{
		loadedContext = dlopen(modulePath.c_str(), RTLD_NOW);
		if (!loadedContext)
		{
			throw new ModuleLoaderException("Failed to open "+modulePath+" - "+string(dlerror()));
		}
	}

	~ModuleLoader()
	{
		if (dlclose(loadedContext) != 0)
		{
			throw new ModuleLoaderException("Failed to close "+modulePath+" - "+string(dlerror()));
	   }
	}

	RetType load()
	{
		void *result = dlsym(loadedContext, symbolToLoad.c_str());
		if (!result)
		{
			throw new ModuleLoaderException("Could not load "+symbolToLoad+" in "+modulePath+" - "+string(dlerror()));
		}


		return ((RetType (*)())result)();
	}

private:
	string modulePath;
	string symbolToLoad;
	void *loadedContext;
};

#endif
