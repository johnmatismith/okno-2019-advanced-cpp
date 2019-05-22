//
// Created by mr on 22.05.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_APPLICATION_H
#define OKNO_2019_ADVANCED_CPP_APPLICATION_H


#include "config/Configuration.h"
#include "db/JsonFileDatabase.h"
#include "engine/ExpressionExecutor.h"
#include "engine/lexer/Lexer.h"
#include "engine/parser/Parser.h"
#include "ui/UserInterface.h"

class Application {
public:
    explicit Application(config::Configuration configuration);

    void run();

private:
    db::JsonFileDatabase openDatabase();
    std::vector<engine::Token> tokenize();

    config::Configuration configuration_;
    ui::UserInterface ui_;

    engine::lexer::Lexer lexer;
    engine::parser::Parser parser_;
    engine::ExpressionExecutor<db::JsonFileDatabase> expressionExecutor_;
};


#endif //OKNO_2019_ADVANCED_CPP_APPLICATION_H
