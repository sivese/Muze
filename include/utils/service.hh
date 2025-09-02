#pragma once

#include <memory>
#include <unordered_map>
#include <typeindex>

class ServiceContainer {
public:
    template<typename T>
    void registerService(std::unique_ptr<T> service) {
        auto type = std::type_index(typeid(T));
        services[type] = std::move(service);
    }

private:
    std::unordered_map<std::type_index, std::unique_ptr<void, void(*)(void*)>> services;
};