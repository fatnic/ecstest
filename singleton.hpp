#ifndef SINGLETON
#define SINGLETON

#include <assert.h>

template <typename T>
class Singleton
{
private:
    static T* _instance;

public:
    Singleton()
    {
        assert(_instance == nullptr);
        if(_instance == nullptr)
            _instance = static_cast<T*>(this);
    }

    virtual ~Singleton()
    {
        _instance = nullptr;
    }

    static T& getInstance()
    {
        return *_instance;
    }

    static T* getInstancePtr()
    {
        return _instance;
    }
};

template <typename T>
T* Singleton<T>::_instance = nullptr;

#endif // SINGLETON

