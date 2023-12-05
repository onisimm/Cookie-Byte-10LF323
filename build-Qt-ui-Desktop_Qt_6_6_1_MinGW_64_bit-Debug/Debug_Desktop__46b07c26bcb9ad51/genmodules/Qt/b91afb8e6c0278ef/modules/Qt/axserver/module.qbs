import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "AxServer"
    Depends { name: "Qt"; submodules: ["core","gui","widgets"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["shell32","advapi32","gdi32","ole32","oleaut32","user32","uuid","mpr","userenv","d3d11","dxgi","dxguid","d3d12"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6AxServer"
    libNameForLinkerRelease: "Qt6AxServer"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6AxServer.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: ["QAXSERVER","QT_AXSERVER_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtAxServer"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["axserver"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
