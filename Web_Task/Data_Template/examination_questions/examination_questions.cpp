//
// Created by fspst on 23-10-29.
//

#include "examination_questions.h"

namespace Epoll_server {
    int examination_questions::getQuestionId() const {
        return Question_id;
    }

    void examination_questions::setQuestionId(int questionId) {
        Question_id = questionId;
    }

    const std::string &examination_questions::getTitleTitle() const {
        return Title_Title;
    }

    void examination_questions::setTitleTitle(const std::string &titleTitle) {
        Title_Title = titleTitle;
    }

    const std::string &examination_questions::getQuestionDifficulty() const {
        return Question_Difficulty;
    }

    void examination_questions::setQuestionDifficulty(const std::string &questionDifficulty) {
        Question_Difficulty = questionDifficulty;
    }

    const std::string &examination_questions::getTheTopicKnowledgePointLabel() const {
        return The_topic_knowledge_point_label;
    }

    void examination_questions::setTheTopicKnowledgePointLabel(const std::string &theTopicKnowledgePointLabel) {
        The_topic_knowledge_point_label = theTopicKnowledgePointLabel;
    }

    const std::string &examination_questions::getBackgroundOfTopic() const {
        return Background_of_Topic;
    }

    void examination_questions::setBackgroundOfTopic(const std::string &backgroundOfTopic) {
        Background_of_Topic = backgroundOfTopic;
    }

    const std::string &examination_questions::getDescriptionOfProblem() const {
        return Description_of_Problem;
    }

    void examination_questions::setDescriptionOfProblem(const std::string &descriptionOfProblem) {
        Description_of_Problem = descriptionOfProblem;
    }

    const std::string &examination_questions::getInputDescription() const {
        return Input_description;
    }

    void examination_questions::setInputDescription(const std::string &inputDescription) {
        Input_description = inputDescription;
    }

    const std::string &examination_questions::getOutputDescription() const {
        return Output_Description;
    }

    void examination_questions::setOutputDescription(const std::string &outputDescription) {
        Output_Description = outputDescription;
    }

    const std::string &examination_questions::getSampleInput() const {
        return Sample_input;
    }

    void examination_questions::setSampleInput(const std::string &sampleInput) {
        Sample_input = sampleInput;
    }

    const std::string &examination_questions::getSampleOutput() const {
        return Sample_output;
    }

    void examination_questions::setSampleOutput(const std::string &sampleOutput) {
        Sample_output = sampleOutput;
    }

    std::string examination_questions::sql_Update() {
        std::string sql="UPDATE `examination_questions` SET ";
        std::string dan_yin="\'";
        std::string dou_hao=",";
        sql+=("Title_Title = "+dan_yin+Title_Title+dan_yin+dou_hao);
        sql+=("Question_Difficulty = "+dan_yin+Question_Difficulty+dan_yin+dou_hao);
        sql+=("The_topic_knowledge_point_label = "+dan_yin+The_topic_knowledge_point_label+dan_yin+dou_hao);
        sql+=("Background_of_Topic = "+dan_yin+Background_of_Topic+dan_yin+dou_hao);
        sql+=("Description_of_Problem = "+dan_yin+Description_of_Problem+dan_yin+dou_hao);
        sql+=("Input_description = "+dan_yin+Input_description+dan_yin+dou_hao);
        sql+=("Output_Description = "+dan_yin+Output_Description+dan_yin+dou_hao);
        sql+=("Sample_input = "+dan_yin+Sample_input+dan_yin+dou_hao);
        sql+=("Sample_output = "+dan_yin+Sample_output+dan_yin+dou_hao);
        sql+=("Time_limit_for_each_test = "+std::to_string(Time_limit_for_each_test))+dou_hao;
        sql+=("creator_id = "+std::to_string(creator_id))+dou_hao;
        sql+=("Input_data = "+dan_yin+Input_data+dan_yin+dou_hao);
        sql+=("Output_data = "+dan_yin+Output_data+dan_yin+dou_hao);
        sql+=("Memory_limit_per_test = "+std::to_string(Memory_limit_per_test));
        sql+=" WHERE ";
        sql+="Question_id = "+std::to_string(Question_id)+";";
        return sql;
    }

    std::string examination_questions::sql_increase() {
        std::string sql;
        std::string dan_yin="\'";
        std::string dou_hao=",";
        sql="INSERT INTO `examination_questions` (`Title_Title`,`Question_Difficulty`,`The_topic_knowledge_point_label`,`Background_of_Topic`,`Description_of_Problem`,`Input_description`,`Output_Description`,`Sample_input`,`Sample_output`,`Time_limit_for_each_test`,`Memory_limit_per_test`,`creator_id`,`Input_data`,`Output_data`)VALUES(";
        sql+=dan_yin+Title_Title+dan_yin+dou_hao;
        sql+=dan_yin+Question_Difficulty+dan_yin+dou_hao;
        sql+=dan_yin+The_topic_knowledge_point_label+dan_yin+dou_hao;
        sql+=dan_yin+Background_of_Topic+dan_yin+dou_hao;
        sql+=dan_yin+Description_of_Problem+dan_yin+dou_hao;
        sql+=dan_yin+Input_description+dan_yin+dou_hao;
        sql+=dan_yin+Output_Description+dan_yin+dou_hao;
        sql+=dan_yin+Sample_input+dan_yin+dou_hao;
        sql+=dan_yin+Sample_output+dan_yin+dou_hao;
        sql+=std::to_string(Time_limit_for_each_test)+dou_hao;
        sql+=std::to_string(Memory_limit_per_test)+dou_hao;
        sql+=std::to_string(creator_id)+dou_hao;
        sql+=dan_yin+Input_data+dan_yin+dou_hao;
        sql+=dan_yin+Output_Description+dan_yin;
        sql+=");";
        return sql;
    }

    std::string examination_questions::sql_Lookup() {
        return std::string();
    }

    std::string examination_questions::sql_Delete() {
        return std::string();
    }

    std::string examination_questions::sql_select_all() {
        std::string sql="SELECT *FROM examination_questions;";
        return sql;
    }

    int examination_questions::getTimeLimitForEachTest() const {
        return Time_limit_for_each_test;
    }

    void examination_questions::setTimeLimitForEachTest(int timeLimitForEachTest) {
        Time_limit_for_each_test = timeLimitForEachTest;
    }

    int examination_questions::getMemoryLimitPerTest() const {
        return Memory_limit_per_test;
    }

    void examination_questions::setMemoryLimitPerTest(int memoryLimitPerTest) {
        Memory_limit_per_test = memoryLimitPerTest;
    }

    std::string examination_questions::sql_select_id() {
        std::string sql="SELECT *FROM examination_questions WHERE Question_id=";
        sql+= std::to_string(Question_id);
        sql+=";";
        return sql;
    }

    int examination_questions::getCreatorId() const {
        return creator_id;
    }

    void examination_questions::setCreatorId(int creatorId) {
        creator_id = creatorId;
    }

    const std::string &examination_questions::getInputData() const {
        return Input_data;
    }

    void examination_questions::setInputData(const std::string &inputData) {
        Input_data = inputData;
    }

    const std::string &examination_questions::getOutputData() const {
        return Output_data;
    }

    void examination_questions::setOutputData(const std::string &outputData) {
        Output_data = outputData;
    }
} // Epoll_server