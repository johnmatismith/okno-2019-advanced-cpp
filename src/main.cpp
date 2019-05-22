
#include "Application.h"
#include "config/Configuration.h"

int main(int argc, char* argv[]) {

    auto const configuration = config::Configuration::parse(argc, argv);

    Application application(configuration);

    application.run();

    return 0;
}
