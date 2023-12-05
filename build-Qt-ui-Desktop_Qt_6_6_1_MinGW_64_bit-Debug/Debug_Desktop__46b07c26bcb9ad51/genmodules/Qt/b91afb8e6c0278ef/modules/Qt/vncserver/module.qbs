import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "VncServer"
    Depends { name: "Qt"; submodules: ["core","gui","network"]}

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
    libNameForLinkerDebug: "Qt6VncServer"
    libNameForLinkerRelease: "Qt6VncServer"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6VncServer.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_VNCSERVER_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtVncServer"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["vncserver"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
