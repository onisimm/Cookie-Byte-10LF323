import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QuickControls2Impl"
    Depends { name: "Qt"; submodules: ["quickcontrols2impl"]}

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
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include/QtQuickControls2Impl/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtQuickControls2Impl/6.6.1/QtQuickControls2Impl"]
    cpp.libraryPaths: []
    
}
