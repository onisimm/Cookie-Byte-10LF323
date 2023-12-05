import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "VncServerQuick"
    Depends { name: "Qt"; submodules: ["core","gui","network","quick","vncserver"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6VncServerQuick"
    libNameForLinkerRelease: "Qt6VncServerQuick"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6VncServerQuick.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_VNCSERVERQUICK_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtVncServerQuick","C:/Qt/6.6.1/mingw_64/include/QtVncServerQuick/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtVncServerQuick/6.6.1/QtVncServerQuick"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["vncserverquick-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
