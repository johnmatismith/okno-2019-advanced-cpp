
#include "Application.h"
#include "config/Configuration.h"

void usage(char* argv[]);

int main(int argc, char* argv[]) {

    auto const configuration = config::Configuration::parse(argc, argv);

    if (!configuration) {
        usage(argv);
        return 1;
    }

    Application application(*configuration);

    application.run();

    return 0;
}

void usage(char* argv[]) {

    std::cout << "Usage:\n"
              << '\t' << argv[0] << " <db path> \"<expression>\"\n"
              << '\n'
              << "\tExample database is present in project repository: db.json\n"
              << "\tExample expressions:\n"
              << "\t\tkey == 'value 1'\n"
              << "\t\tkey == 'value 1' && other_key == 'other value 1'\n"
              << "\t\tnumber > 1 && number <= 4\n"
              << "\t\tkey != 'value 1'\n"
              << "\t\tkey == 'value 1' && other_key == 'other value 1' || other_key == 'other value 2'\n"
              << "\t\tkey == 'value 1' && (other_key == 'other value 1' || other_key == 'other value 2')\n" << std::endl;
}
