#pragma once

#include <stdint.h>

#define COROS_ERROR_RETURN -1
#define BIT(x) (1 << x)

// Cs represents Coros
// Cs = Coros

namespace Coros
{
    // ---- List of all of the data types used ----
    struct Vec2;
    struct Vec3;
    struct Vec4;

    struct UUID;

    struct IO;

    struct WindowContext;
    // The class which handles all of the window context in the Application
    struct WindowContextManager;

    // Stores all of the data required for the Library
    struct Core;

    // Events Struct Decls ---- TODO ----
    struct Events;
    struct MouseButtonEvent;
    struct KeyEvent;
    struct CharEvent;
    struct WindowResizeEvent;
    struct WindowCloseEvent;
    struct CursorEvent;

    // ---- Enums ----
    enum class WindowPlatforms
    {
        None,
        GLFW,
        SDL2
    };

    enum CorosKeys
    {
        // Number keys
        CorosKey_None,
        CorosKey_1,
        CorosKey_2,
        CorosKey_3,
        CorosKey_4,
        CorosKey_5,
        CorosKey_6,
        CorosKey_7,
        CorosKey_8,
        CorosKey_9,
        CorosKey_0,

        // Alphabets A-Z
        CorosKey_A,
        CorosKey_B,
        CorosKey_C,
        CorosKey_D,
        CorosKey_E,
        CorosKey_F,
        CorosKey_G,
        CorosKey_H,
        CorosKey_I,
        CorosKey_J,
        CorosKey_K,
        CorosKey_L,
        CorosKey_M,
        CorosKey_N,
        CorosKey_O,
        CorosKey_P,
        CorosKey_Q,
        CorosKey_R,
        CorosKey_S,
        CorosKey_T,
        CorosKey_U,
        CorosKey_V,
        CorosKey_W,
        CorosKey_X,
        CorosKey_Y,
        CorosKey_Z,

        CorosKey_CapsLock,
        CorosKey_NumLock,
        CorosKey_Enter,
        CorosKey_Escape,
        CorosKey_Comma,

        // Keys
        CorosKey_RightAlt,
        CorosKey_LeftAlt,
        CorosKey_RightBracket,
        CorosKey_LeftBracket,
        CorosKey_LeftShift,
        CorosKey_RightShift,
        CorosKey_LeftCtrl,
        CorosKey_RightCtrl,
        CorosKey_RightSuper,
        CorosKey_LeftSuper,

        // Numpad Keys
        CorosKey_Np_0,
        CorosKey_Np_1,
        CorosKey_Np_2,
        CorosKey_Np_3,
        CorosKey_Np_5,
        CorosKey_Np_4,
        CorosKey_Np_6,
        CorosKey_Np_7,
        CorosKey_Np_8,
        CorosKey_Np_9,

        // Arithemetic signs
        CorosKey_Np_Add,
        CorosKey_Np_Minus,
        CorosKey_Np_Multiply,
        CorosKey_Np_Divide,

        // MouseButtons
        CorosKey_MouseButtonLeft,
        CorosKey_MouseButtonRight,
        CorosKey_MouseButtonMiddle,

        // Mods
        CorosKey_ModAlt,
        CorosKey_ModCapsLock,
        CorosKey_ModNumLock,
        CorosKey_ModShift,
        CorosKey_ModSuper,
        CorosKey_ModCtrl,
    };

    enum CorosMods
    {
        COROS_MOD_NONE,
        COROS_MOD_SHIFT = BIT(0),
        COROS_MOD_ALT = BIT(1),
        COROS_MOD_CAPSLOCK = BIT(2),
        COROS_MOD_NUMLOCK = BIT(3),
        COROS_MOD_CTRL = BIT(4),
        COROS_MOD_SUPER = BIT(5),
    };

    const char *WindowPlatform2Str(WindowPlatforms Platform);

    // ---- The Main use functions ----
    void Init();
    void ShutDown();

    void CreateCore();
    bool IsCoreCreated();

    void BeginWindow(const std::string &Name);
    void EndWindow();

    int GetWindowContextCount();

    // Clears all of the WindowContexts from the manager
    void ClearWindowContexts();

    // Returns -1 if no Window Found
    UUID FindWindow(const char *WinName);

    WindowContextManager &GetWindowContextManager();
    IO &GetIO();

    void Update(bool Loop = false);

    // ---- The Struct Declarations ----

    struct Vec2
    {
        float x, y;

        Vec2(float x_ = 0.0f, float y_ = 0.0f)
            : x(x_), y(y_) {}

        inline bool operator==(const Vec2 &other) { return (other.x == x) && (other.y == y); }
    };

    struct Vec3
    {
        float x, y, z;

        Vec3(float x_ = 0.0f, float y_ = 0.0f, float z_ = 0.0f)
            : x(x_), y(y_), z(z_) {}
        
        inline bool operator==(const Vec3 &other) { return (other.x == x) && (other.y == y) && (other.z == z); }
    };

    struct Vec4
    {
        float x, y, z, w;

        Vec4(float x_ = 0.0f, float y_ = 0.0f, float z_ = 0.0f, float w_ = 0.0f)
            : x(x_), y(y_), z(z_), w(w_) {}

        inline bool operator==(const Vec4 &other) { return (other.x == x) && (other.y == y) && (other.z == z) && (other.w == w); }
    };

    struct UUID
    {
    public:
        UUID();
        UUID(uint64_t uuid);
        UUID(const UUID &) = default;

        operator uint64_t() const { return m_UUID; }

    private:
        uint64_t m_UUID;
    };

    struct WindowContext
    {
    public:
        WindowContext(const std::string &Name = "Untitled", const Vec2 &Scale = Vec2(180, 100), const Vec2 &Pos = Vec2(0, 0),
                      UUID ID = UUID());
        ~WindowContext();

        Vec2 &GetScale() { return _Scale; }
        const Vec2 &GetScale() const { return _Scale; }

        Vec2 &GetPos() { return _Pos; }
        const Vec2 &GetPos() const { return _Pos; }

        UUID GetID() const { return _ID; }
        const std::string &GetName() const { return _Name; }

    private:
        Vec2 _Scale, _Pos;
        // TODO: Use a custom string struct instead of std::string
        std::string _Name;
        UUID _ID;
    };

    struct IO
    {
        Vec2 WindowSize;
        Vec2 CursorPos;

        void *WindowPlatformPointer;
        WindowPlatforms WindowPlatformType;

        // Stores the Active KeyBoard Mods
        int ActiveMods = COROS_MOD_NONE;
        // Stores the Current Pressed Key
        CorosKeys PressedKey;
        // Stores the Current MouseButton
        CorosKeys PressedMouseButton;

        // The Window that the cursor is inside
        WindowContext *CursorWindow;

        void AddKeyEvent(CorosKeys Key, bool KeyPressed);
        void AddKeyModEvent(CorosMods Mod, bool Pressed);
        void AddMouseButtonEvent(CorosKeys MouseButton, bool Pressed);
        void AddCursorPosEvent(const Vec2 &Pos);
    };

} // namespace Coros

namespace std
{
    template <typename T>
    struct hash;

    template <>
    struct hash<Coros::UUID>
    {
        size_t operator()(const Coros::UUID &uuid) const
        {
            return (uint64_t)uuid;
        }
    };

    template <>
    struct hash<Coros::WindowContext>
    {
        size_t operator()(const Coros::WindowContext &WinContext) const
        {
            return (uint64_t)WinContext.GetID();
        }
    };

}

namespace Coros
{
    struct WindowContextManager
    {
    public:
        WindowContextManager();
        ~WindowContextManager();

        UUID AddWindow(const std::string &Name, const Vec2 &Scale, const Vec2 &Pos);
        UUID AddWindow(const WindowContext &Win);

        WindowContext &GetWindow(UUID ID);
        WindowContext &GetWindow(const char *Name);

        WindowContext PopWindow();
        WindowContext PopWindow(int i);

        bool IsWindowContextPresent(UUID ID);
        UUID IsWindowContextPresent(const char *Name);

        int Count() const { return _Windows.size(); }

        void Clear();

    private:
        std::unordered_map<UUID, WindowContext> _Windows;
    };

    struct Core
    {
    public:
        Core();
        ~Core();

        IO &GetIO() { return _IO; }
        WindowContextManager &GetWindowsContextManager() { return _WinContextManager; }

    private:
        IO _IO;
        WindowContextManager _WinContextManager;
    };
} // namespace Coros
