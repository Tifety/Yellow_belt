#include "node.h"

bool EmptyNode::Evaluate (const Date& base_date, const string& base_event) const  {
    return true;
}

bool DateComparisonNode::Evaluate (const Date& base_date, const string& base_event) const {
    switch (cmp) {
        case Comparison::Less:
            return (base_date < condition_date);
        case Comparison::LessOrEqual:
            return ((base_date < condition_date || base_date==condition_date));
        case Comparison::Greater:
            return (!(base_date < condition_date) && !(base_date == condition_date));
        case Comparison::GreaterOrEqual:
            return !(base_date < condition_date);
        case Comparison::Equal:
            return (base_date == condition_date);
        case Comparison::NotEqual:
            return !(base_date==condition_date);
        default:
            return false;
        }
}

bool EventComparisonNode::Evaluate(const Date &base_date, const string &base_event) const {
    switch (cmp) {
        case Comparison::Less:
            return (base_event < condition_event);
        case Comparison::LessOrEqual:
            return (base_event <= condition_event);
        case Comparison::Greater:
            return (base_event > condition_event);
        case Comparison::GreaterOrEqual:
            return (base_event >= condition_event);
        case Comparison::Equal:
            return condition_event == base_event;
        case Comparison::NotEqual:
            return condition_event != base_event;
        default:
            return false;
    }
}

bool LogicalOperationNode::Evaluate(const Date &date_in, const string &event_in) const {
    switch (Op) {
        case LogicalOperation::And:
            return (left->Evaluate(date_in, event_in) && right->Evaluate(date_in, event_in));
        case LogicalOperation::Or:
            return (left->Evaluate(date_in, event_in) || right->Evaluate(date_in, event_in));
    }
    return true;
}


