workspace "Nina" 
    architecture "x64"
    configurations { "Debug", "Release", "Dist" } 
    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- use lua table to add the include dirs
IncludeDir = {}
IncludeDir["GLFW"] = "NinaEngine/dependence/GLFW/include"

-- include the sub premake5.lua
include "NinaEngine/dependence/GLFW"

project "NinaEngine"  
    location "NinaEngine"
    kind "SharedLib"  
    language "C++"   
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
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter { "system:windows" } 
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "NINA_PLATFORM_WINDOWS",
            "NINA_BUILD_DLL",
        }

        postbuildcommands
        {
            "{MKDIR} ../bin/" .. outputdir .. "/Sandbox",
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox",
        }

    filter { "configurations:Debug" }
        defines { "NINA_DEBUG" }
        buildoptions "/MDd"
        symbols "On"

    filter { "configurations:Release" }
        defines { "NINA_RELEASE" }
        buildoptions "/MD"
        optimize "On"

    filter { "configurations:Dist" }
        defines { "NINA_DIST" }
        buildoptions "/MD"
        optimize "On"


project "Sandbox"  
    location "Sandbox"
    kind "ConsoleApp"  
    language "C++"   
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
    }

    links
    {
        "NinaEngine"
    }

    filter { "system:windows" } 
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "NINA_PLATFORM_WINDOWS",
        }

    filter { "configurations:Debug" }
        defines { "NINA_DEBUG" }
        buildoptions "/MDd"
        symbols "On"

    filter { "configurations:Release" }
        defines { "NINA_RELEASE" }
        buildoptions "/MD"
        optimize "On"

    filter { "configurations:Dist" }
        defines { "NINA_DIST" }
        buildoptions "/MD"
        optimize "On"