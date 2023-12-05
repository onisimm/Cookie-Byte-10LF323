import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "InsightTrackerQml"
    Depends { name: "Qt"; submodules: ["core","qml","quick","insighttracker-private"]}

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
    libNameForLinkerDebug: "Qt6InsightTrackerQml"
    libNameForLinkerRelease: "Qt6InsightTrackerQml"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6InsightTrackerQml.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_INSIGHTTRACKERQML_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtInsightTrackerQml"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["insighttrackerqml"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
