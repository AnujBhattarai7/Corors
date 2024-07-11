#include "PCH/PCH.h"
#include "Coros.h"

namespace Coros
{
    static Core *_CoreContext = nullptr;
    static WindowContext *_CurrentWindowContext = nullptr;

    const char *WindowPlatform2Str(WindowPlatforms Platform)
    {
        if(Platform == WindowPlatforms::GLFW)
            return "WINDOW_PLATFORM_GLFW";
        if(Platform == WindowPlatforms::SDL2)
            return "WINDOW_PLATFORM_SDL2";
        return nullptr;
    }

    void Init()
    {
        COROS_PRINT("Init")
    }

    void ShutDown()
    {
        COROS_PRINT("ShutDown")

        if (IsCoreCreated())
        {
            delete _CoreContext;
            _CoreContext = nullptr;
        }
    }

    void CreateCore()
    {
        _CoreContext = new Core();
    }

    bool IsCoreCreated()
    {
        return _CoreContext != nullptr;
    }

    void BeginWindow(const std::string &Name)
    {
        if (_CurrentWindowContext != nullptr)
            COROS_ERROR("Call EndWindow!! for: " << _CurrentWindowContext->GetName())

        UUID CurrentWinID = FindWindow(Name.c_str());

        // If the window is present then set the CurrentWindow Pointer to it
        if (CurrentWinID != COROS_ERROR_RETURN)
        {
            _CurrentWindowContext = &GetWindowContextManager().GetWindow(CurrentWinID);
            return;
        }

        // If it is a unique name then create a new window and get its ID and refer it to the pointer
        CurrentWinID = _CoreContext->GetWindowsContextManager().AddWindow(Name, {180, 100}, {0, 0});
        _CurrentWindowContext = &GetWindowContextManager().GetWindow(CurrentWinID);
    }

    void EndWindow()
    {
        if (_CurrentWindowContext == nullptr)
            COROS_ERROR("End Already Called")
        _CurrentWindowContext = nullptr;
    }

    int GetWindowContextCount()
    {
        return GetWindowContextManager().Count();
    }

    void ClearWindowContexts()
    {
        GetWindowContextManager().Clear();
    }

    UUID FindWindow(const char *WinName)
    {
        UUID ID = GetWindowContextManager().IsWindowContextPresent(WinName);
        return ID;
    }

    WindowContextManager &GetWindowContextManager()
    {
        return _CoreContext->GetWindowsContextManager();
    }

    IO &GetIO()
    {
        return _CoreContext->GetIO();
    }

    void Update(bool Loop)
    {
    }

    Core::Core()
    {
    }

    Core::~Core()
    {
    }

    WindowContext::WindowContext(const std::string &Name, const Vec2 &Scale, const Vec2 &Pos, UUID ID)
        : _Name(Name), _Pos(Pos), _Scale(Scale), _ID(ID)
    {
    }

    WindowContext::~WindowContext()
    {
    }

    static std::random_device s_RandomDevice;
    static std::mt19937_64 s_Engine(s_RandomDevice());
    static std::uniform_int_distribution<uint64_t> s_UniformDistribution;

    UUID::UUID()
        : m_UUID(s_UniformDistribution(s_Engine))
    {
    }

    UUID::UUID(uint64_t uuid)
        : m_UUID(uuid)
    {
    }

    WindowContextManager::WindowContextManager()
    {
    }

    WindowContextManager::~WindowContextManager()
    {
        Clear();
    }

    UUID WindowContextManager::AddWindow(const std::string &Name, const Vec2 &Scale, const Vec2 &Pos)
    {
        if (IsWindowContextPresent(Name.c_str()) == COROS_ERROR_RETURN)
        {
            UUID WinID;
            _Windows[WinID] = WindowContext(Name, Scale, Pos, WinID);
            return WinID;
        }
    }

    UUID WindowContextManager::AddWindow(const WindowContext &Win)
    {
        if (IsWindowContextPresent(Win.GetID()) == false)
            _Windows[Win.GetID()] = Win;
        return Win.GetID();
    }

    WindowContext &WindowContextManager::GetWindow(UUID ID)
    {
        if (IsWindowContextPresent(ID))
            return _Windows[ID];
    }

    WindowContext &WindowContextManager::GetWindow(const char *Name)
    {
        UUID ID = IsWindowContextPresent(Name);
        if (ID != COROS_ERROR_RETURN)
            return _Windows[ID];
    }

    WindowContext WindowContextManager::PopWindow()
    {
    }

    WindowContext WindowContextManager::PopWindow(int i)
    {
    }

    bool WindowContextManager::IsWindowContextPresent(UUID ID)
    {
        return _Windows.find(ID) != _Windows.end();
    }

    UUID WindowContextManager::IsWindowContextPresent(const char *Name)
    {
        for (auto &i : _Windows)
            if (i.second.GetName() == Name)
                return i.first;
        return COROS_ERROR_RETURN;
    }

    void WindowContextManager::Clear()
    {
        _Windows.clear();
    }
   
    void IO::AddKeyEvent(CorosKeys Key, bool KeyPressed)
    {
        if(KeyPressed)
        {
            this->PressedKey = Key;
            // Add teh Event to the Event Quees Manager
            return;
        }
        this->PressedKey = CorosKey_None;
    }
   
    void IO::AddKeyModEvent(CorosMods Mod, bool Pressed)
    {

    }
   
    void IO::AddMouseButtonEvent(CorosKeys MouseButton, bool Pressed)
    {
        if(Pressed)
        {
            this->PressedMouseButton = MouseButton;
            // Add teh Event to the Event Quees Manager
            return;
        }
        this->PressedMouseButton = CorosKey_None;
    }
    
    void IO::AddCursorPosEvent(const Vec2 &Pos)
    {
        this->CursorPos = Pos;
        // ADe The Event
    }
} // namespace Coros
