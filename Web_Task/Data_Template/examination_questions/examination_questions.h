//
// Created by fspst on 23-10-29.
//
#include "../../../xt_heard/xt_heard.h"
#ifndef DATASTRUCTPLAYGROUND_SERVER_QUESTION_TEST_INFORMATION_H
#define DATASTRUCTPLAYGROUND_SERVER_QUESTION_TEST_INFORMATION_H

namespace Epoll_server {

    class examination_questions {
    public:
        int getQuestionId() const;

        void setQuestionId(int questionId);

        const std::string &getTitleTitle() const;

        void setTitleTitle(const std::string &titleTitle);

        const std::string &getQuestionDifficulty() const;

        void setQuestionDifficulty(const std::string &questionDifficulty);

        const std::string &getTheTopicKnowledgePointLabel() const;

        void setTheTopicKnowledgePointLabel(const std::string &theTopicKnowledgePointLabel);

        const std::string &getBackgroundOfTopic() const;

        void setBackgroundOfTopic(const std::string &backgroundOfTopic);

        const std::string &getDescriptionOfProblem() const;

        void setDescriptionOfProblem(const std::string &descriptionOfProblem);

        const std::string &getInputDescription() const;

        void setInputDescription(const std::string &inputDescription);

        const std::string &getOutputDescription() const;

        void setOutputDescription(const std::string &outputDescription);

        const std::string &getSampleInput() const;

        void setSampleInput(const std::string &sampleInput);

        const std::string &getSampleOutput() const;

        void setSampleOutput(const std::string &sampleOutput);
        std::string sql_increase();
        std::string sql_Delete();
        std::string sql_Update();
        std::string sql_Lookup();
        std::string sql_select_all();
        std::string sql_select_id();
    private:
        int Question_id;//题目编号
        std::string Title_Title="";//题目标题
        std::string Question_Difficulty="";//题目难度
        std::string The_topic_knowledge_point_label="";//题目知识点标签
        std::string Background_of_Topic="";//题目背景
        std::string Description_of_Problem="";//题目描述
        std::string Input_description="";//输入描述
        std::string Output_Description="";//输出描述
        std::string Sample_input="";//样例输入
        std::string Sample_output="";//样例输出
        int Time_limit_for_each_test=1000;//时间限制ms
        int Memory_limit_per_test=128;//空间限制 128mb
        int creator_id;//创建者id
        std::string Input_data;//输入数据
        std::string Output_data;//输出数据
    public:
        int getCreatorId() const;

        void setCreatorId(int creatorId);

        const std::string &getInputData() const;

        void setInputData(const std::string &inputData);

        const std::string &getOutputData() const;

        void setOutputData(const std::string &outputData);

    public:
        int getTimeLimitForEachTest() const;

        void setTimeLimitForEachTest(int timeLimitForEachTest);

        int getMemoryLimitPerTest() const;

        void setMemoryLimitPerTest(int memoryLimitPerTest);
    };

} // Epoll_server

#endif //DATASTRUCTPLAYGROUND_SERVER_QUESTION_TEST_INFORMATION_H
