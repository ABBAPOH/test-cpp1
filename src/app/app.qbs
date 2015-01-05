import qbs.base 1.0
import qbs.Process

Application {
    name: project.app_target
    destinationDirectory: project.install_app_path
    consoleApplication : qbs.debugInformation

    Depends { name: "cpp" }
    Depends { id: qtcore; name: "Qt.core" }
    Depends { name: "Qt.widgets" }

    Properties {
        condition: qbs.targetOS.contains("unix") && !qbs.targetOS.contains("osx")
        cpp.rpaths: [ "$ORIGIN/../lib/" + project.app_target ]
    }

    Properties {
        condition: qbs.targetOS.contains("osx")
        cpp.minimumOsxVersion: "10.7"
    }

    cpp.cxxFlags: project.cxxFlags
    cpp.linkerFlags: project.linkFlags

    files: [ "*.cpp", "*.h" ]

    Group {
        fileTagsFilter: product.type
        qbs.install: true
        qbs.installDir: project.install_app_path
    }
}
