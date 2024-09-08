workspace "Nina" 
    architecture "x64"
    configurations { "Debug", "Release", "Dist" } 
    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- use lua table to add the include dirs
IncludeDir = {}
IncludeDir["GLFW"] = "NinaEngine/dependence/GLFW/include"
IncludeDir["Glad"] = "NinaEngine/dependence/Glad/include"
IncludeDir["ImGui"] = "NinaEngine/dependence/imgui"

-- include the sub premake5.lua
include "NinaEngine/dependence/GLFW"
include "NinaEngine/dependence/Glad"
include "NinaEngine/dependence/imgui"

project "NinaEngine"  
    location "NinaEngine"
    kind "SharedLib"  
    language "C++"   
    staticruntime "off"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "ninapch.h"
    pchsource "NinaEngine/src/ninapch.cpp"
    
    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/dependence/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter { "system:windows" } 
        cppdialect "C++17"
        systemversion "latest"

        defines 
        {
            "NINA_PLATFORM_WINDOWS",
            "NINA_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            "{MKDIR} ../bin/" .. outputdir .. "/Sandbox",
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox",
        }

    filter { "configurations:Debug" }
        defines { "NINA_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter { "configurations:Release" }
        defines { "NINA_RELEASE" }
        runtime "Release"
        optimize "On"

    filter { "configurations:Dist" }
        defines { "NINA_DIST" }
        runtime "Release"
        optimize "On"


project "Sandbox"  
    location "Sandbox"
    kind "ConsoleApp"  
    language "C++"   
    staticruntime "off"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }
    
    includedirs
    {
        "%{prj.name}/src",
        "NinaEngine/dependence/spdlog/include",
        "NinaEngine/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "NinaEngine"
    }

    filter { "system:windows" } 
        cppdialect "C++17"
        systemversion "latest"

        defines 
        {
            "NINA_PLATFORM_WINDOWS",
        }

    filter { "configurations:Debug" }
        defines { "NINA_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter { "configurations:Release" }
        defines { "NINA_RELEASE" }
        runtime "Release"
        optimize "On"

    filter { "configurations:Dist" }
        defines { "NINA_DIST" }
        runtime "Release"
        optimize "On"