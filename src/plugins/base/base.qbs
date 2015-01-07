import qbs.base 1.0

DynamicLibrary {
    name : "base"
    destinationDirectory: project.install_plugin_path

    Depends { name: "cpp" }
    Depends { name: "Qt"; submodules: ["core", "gui"] }

    Properties {
        condition: qbs.targetOS.contains("unix") && !qbs.targetOS.contains("osx")
        cpp.rpaths: [ "$ORIGIN/../lib/" + project.app_target ]
    }

    Properties {
        condition: qbs.targetOS.contains("osx")
        cpp.minimumOsxVersion: "10.7"
    }

    cpp.includePaths: project.includePaths
    cpp.cxxFlags: project.cxxFlags
    cpp.linkerFlags: project.linkFlags

    files : [ "*.cpp", "*.h" ]

    Group {
        fileTagsFilter: product.type
        qbs.install: true
        qbs.installDir: project.install_plugin_path
    }
}
