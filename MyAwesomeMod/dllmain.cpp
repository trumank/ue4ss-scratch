#include <string>
#include <stdio.h>

#include <GUI/GUITab.hpp>
#include <Mod/CppUserModBase.hpp>
#include <UE4SSProgram.hpp>

class MyTestTab : public GUI::GUITab
{
public:
    MyTestTab() : RC::GUI::GUITab()
    {
        TabName = L"MyAwesomeMod Tab";
    }

    auto render() -> void override
    {
        ImGui::Text("my super awesome interface");
    }
};

class MyAwesomeMod : public RC::CppUserModBase
{
private:
    std::shared_ptr<MyTestTab> m_test_tab{};

public:
    MyAwesomeMod() : CppUserModBase()
    {
        ModName = STR("MyAwesomeMod");
        ModVersion = STR("1.0");
        ModDescription = STR("This is my awesome mod");
        ModAuthors = STR("UE4SS Team");

        ImGui::SetCurrentContext(UE4SSProgram::get_current_imgui_context());
        ImGuiMemAllocFunc alloc_func{};
        ImGuiMemFreeFunc free_func{};
        void* user_data{};
        UE4SSProgram::get_current_imgui_allocator_functions(&alloc_func, &free_func, &user_data);
        ImGui::SetAllocatorFunctions(alloc_func, free_func, user_data);

        m_test_tab = std::make_unique<MyTestTab>();
        UE4SSProgram::get_program().add_gui_tab(m_test_tab);
    }

    ~MyAwesomeMod()
    {
        if (m_test_tab)
            UE4SSProgram::get_program().remove_gui_tab(m_test_tab);
    }

    auto on_update() -> void override
    {
    }
};

#define MY_AWESOME_MOD_API __declspec(dllexport)
extern "C"
{
    MY_AWESOME_MOD_API RC::CppUserModBase* start_mod()
    {
        return new MyAwesomeMod();
    }

    MY_AWESOME_MOD_API void uninstall_mod(RC::CppUserModBase* mod)
    {
        delete mod;
    }
}

