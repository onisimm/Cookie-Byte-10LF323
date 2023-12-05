import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "MultimediaQuick"
    Depends { name: "Qt"; submodules: ["core","multimedia-private","quick","quick-private"]}

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
    libNameForLinkerDebug: "Qt6MultimediaQuick"
    libNameForLinkerRelease: "Qt6MultimediaQuick"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6MultimediaQuick.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_MULTIMEDIAQUICK_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtMultimediaQuick","C:/Qt/6.6.1/mingw_64/include/QtMultimediaQuick/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtMultimediaQuick/6.6.1/QtMultimediaQuick"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["multimediaquick-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
