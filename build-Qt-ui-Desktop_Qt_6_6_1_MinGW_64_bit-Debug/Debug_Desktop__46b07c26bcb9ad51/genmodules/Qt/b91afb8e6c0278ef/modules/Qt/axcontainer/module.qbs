import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "AxContainer"
    Depends { name: "Qt"; submodules: ["core","gui","widgets"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["advapi32","gdi32","ole32","oleaut32","user32","uuid","mpr","userenv","d3d11","dxgi","dxguid","d3d12"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6AxContainer"
    libNameForLinkerRelease: "Qt6AxContainer"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6AxContainer.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: ["QT_AXCONTAINER_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtAxContainer"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["axcontainer"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
