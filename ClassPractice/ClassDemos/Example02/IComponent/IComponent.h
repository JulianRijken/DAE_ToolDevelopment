#include <Concepts>

template<typename C>
concept IsComponent = requires(C component, float deltaTime){
    {component.Update(deltaTime)} -> std::same_as<void>;
    {component.Draw()} ->std::same_as<void>;
};