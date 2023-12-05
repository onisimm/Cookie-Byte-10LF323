import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "qtfreetype"
    Depends { name: "Qt"; submodules: []}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: ["C:/Qt/6.6.1/mingw_64/lib/libQt6BundledFreetype.a"]
    staticLibsRelease: ["C:/Qt/6.6.1/mingw_64/lib/libQt6BundledFreetype.a"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "qtfreetype"
    libNameForLinkerRelease: "qtfreetype"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6BundledFreetype.a"
    pluginTypes: []
    moduleConfig: []
    cpp.defines: ["QT_FREETYPE_LIB"]
    cpp.systemIncludePaths: ["C:/Users/qt/work/qt/qtbase/src/3rdparty/freetype/include"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["freetype"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
