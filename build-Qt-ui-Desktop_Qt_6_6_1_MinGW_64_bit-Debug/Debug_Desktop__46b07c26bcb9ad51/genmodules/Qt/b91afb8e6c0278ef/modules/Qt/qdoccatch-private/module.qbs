import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QDocCatch"
    Depends { name: "Qt"; submodules: []}

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
    cpp.defines: ["QT_QDOCCATCH_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQDocCatch","C:/Qt/6.6.1/mingw_64/include/QtQDocCatch/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtQDocCatch/6.6.1/QtQDocCatch"]
    cpp.libraryPaths: []
    
}
