workspace "Nina" 
    architecture "x64"
    configurations { "Debug", "Release", "Dist" } 
    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "NinaEngine"  
    location "NinaEngine"
    kind "SharedLib"  
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
        "%{prj.name}/dependence/spdlog/include",
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
        symbols "On"

    filter { "configurations:Release" }
        defines { "NINA_RELEASE" }
        optimize "On"

    filter { "configurations:Dist" }
        defines { "NINA_DIST" }
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
        symbols "On"

    filter { "configurations:Release" }
        defines { "NINA_RELEASE" }
        optimize "On"

    filter { "configurations:Dist" }
        defines { "NINA_DIST" }
        optimize "On"