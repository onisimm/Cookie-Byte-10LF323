import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Quick3DIblBaker"
    Depends { name: "Qt"; submodules: ["quick3druntimerender-private","gui-private","quick3diblbaker"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: false
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
    libNameForLinkerDebug: undefined
    libNameForLinkerRelease: undefined
    libFilePathDebug: undefined
    libFilePathRelease: undefined
    pluginTypes: []
    moduleConfig: []
    cpp.defines: []
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include/QtQuick3DIblBaker/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtQuick3DIblBaker/6.6.1/QtQuick3DIblBaker"]
    cpp.libraryPaths: []
    
}
