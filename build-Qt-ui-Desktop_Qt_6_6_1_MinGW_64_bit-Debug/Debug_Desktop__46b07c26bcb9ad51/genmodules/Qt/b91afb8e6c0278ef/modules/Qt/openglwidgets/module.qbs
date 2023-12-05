import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "OpenGLWidgets"
    Depends { name: "Qt"; submodules: ["opengl","widgets"]}

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
    libNameForLinkerDebug: "Qt6OpenGLWidgets"
    libNameForLinkerRelease: "Qt6OpenGLWidgets"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6OpenGLWidgets.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_OPENGLWIDGETS_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtOpenGLWidgets"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["openglwidgets"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
