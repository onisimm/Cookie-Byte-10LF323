import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "InsightTracker"
    Depends { name: "Qt"; submodules: ["core","core-private","gui","network","sql"]}

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
    libNameForLinkerDebug: "Qt6InsightTracker"
    libNameForLinkerRelease: "Qt6InsightTracker"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6InsightTracker.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_INSIGHTTRACKER_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtInsightTracker"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["insighttracker"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
