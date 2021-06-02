#pragma once
#include "date.h"
#include <memory>

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
};

enum class LogicalOperation {
    And,
    Or
};

class Node {
public:
   virtual bool Evaluate(const Date& base_date, const string& base_event) const =0;
};

class EmptyNode: public Node {
public:
    bool Evaluate (const Date& base_date, const string& base_event) const override;
};

class DateComparisonNode: public Node {
public:
    DateComparisonNode (const Comparison& cmp_in,const Date& date_in ) : cmp(cmp_in), condition_date(date_in) {};
    bool Evaluate (const Date& date_in, const string& event_in) const override;

private:
    const Comparison cmp;
    const Date condition_date;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode (const Comparison& cmp_in, const string& event_in) : cmp(cmp_in), condition_event(event_in) {};
    bool Evaluate(const Date &base_date, const string &base_event) const override;

private:
   const Comparison cmp;
   const string condition_event;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode (const LogicalOperation& Op_in, shared_ptr<Node> Node_left, shared_ptr<Node> Node_right)
    : Op(Op_in), left(Node_left), right(Node_right) {};
    bool Evaluate (const Date& date_in, const string& event_in) const override;
private:
    const LogicalOperation Op;
    const shared_ptr<Node> left;
    const shared_ptr<Node> right;
};

