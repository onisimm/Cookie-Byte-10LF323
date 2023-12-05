import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "SpatialAudio"
    Depends { name: "Qt"; submodules: ["multimedia"]}

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
    libNameForLinkerDebug: "Qt6SpatialAudio"
    libNameForLinkerRelease: "Qt6SpatialAudio"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6SpatialAudio.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_SPATIALAUDIO_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtSpatialAudio"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["spatialaudio"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
