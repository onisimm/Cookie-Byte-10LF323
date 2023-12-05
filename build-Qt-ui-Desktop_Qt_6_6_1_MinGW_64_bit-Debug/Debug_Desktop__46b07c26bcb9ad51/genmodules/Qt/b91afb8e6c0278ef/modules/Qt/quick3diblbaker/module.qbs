import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Quick3DIblBaker"
    Depends { name: "Qt"; submodules: ["core","gui","quick","quick3druntimerender"]}

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
    libNameForLinkerDebug: "Qt6Quick3DIblBaker"
    libNameForLinkerRelease: "Qt6Quick3DIblBaker"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6Quick3DIblBaker.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QUICK3DIBLBAKER_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQuick3DIblBaker"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["quick3diblbaker"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
