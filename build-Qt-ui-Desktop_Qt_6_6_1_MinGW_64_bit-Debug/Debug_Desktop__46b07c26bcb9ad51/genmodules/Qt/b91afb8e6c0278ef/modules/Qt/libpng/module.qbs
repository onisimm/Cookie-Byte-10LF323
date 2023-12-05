import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "qtlibpng"
    Depends { name: "Qt"; submodules: []}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: ["C:/Qt/6.6.1/mingw_64/lib/libQt6BundledLibpng.a"]
    staticLibsRelease: ["C:/Qt/6.6.1/mingw_64/lib/libQt6BundledLibpng.a"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "qtlibpng"
    libNameForLinkerRelease: "qtlibpng"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6BundledLibpng.a"
    pluginTypes: []
    moduleConfig: []
    cpp.defines: ["QT_LIBPNG_LIB"]
    cpp.systemIncludePaths: ["C:/Users/qt/work/qt/qtbase/src/3rdparty/libpng"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["libpng"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
