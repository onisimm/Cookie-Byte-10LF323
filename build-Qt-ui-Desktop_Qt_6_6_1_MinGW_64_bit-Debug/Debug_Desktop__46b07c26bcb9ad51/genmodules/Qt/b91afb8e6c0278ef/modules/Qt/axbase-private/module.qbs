import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "AxBase"
    Depends { name: "Qt"; submodules: ["core","core-private","gui","gui-private","widgets"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["mpr","userenv","d3d11","dxgi","dxguid","d3d12","advapi32","gdi32","ole32","oleaut32","user32","uuid"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6AxBase"
    libNameForLinkerRelease: "Qt6AxBase"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6AxBase.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: ["QT_AXBASE_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtAxBase","C:/Qt/6.6.1/mingw_64/include/QtAxBase/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtAxBase/6.6.1/QtAxBase"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["axbase-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
