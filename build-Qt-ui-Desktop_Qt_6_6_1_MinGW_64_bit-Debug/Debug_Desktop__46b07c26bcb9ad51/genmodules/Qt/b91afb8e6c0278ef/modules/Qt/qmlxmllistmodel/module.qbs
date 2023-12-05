import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlXmlListModel"
    Depends { name: "Qt"; submodules: ["core","qml"]}

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
    libNameForLinkerDebug: "Qt6QmlXmlListModel"
    libNameForLinkerRelease: "Qt6QmlXmlListModel"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6QmlXmlListModel.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QMLXMLLISTMODEL_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQmlXmlListModel"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["qmlxmllistmodel"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
