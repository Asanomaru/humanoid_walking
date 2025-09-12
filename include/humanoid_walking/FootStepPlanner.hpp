#include <vector>
#include <deque>

namespace foot_step_planner {

//着地位置
struct Footstep {
    enum Leg {Right Left};
    Leg leg;
    double px;
    double py;
};

//歩行パラメータ
struct WalkParam {
    double sx;
    double sy;
};

class FootStepPlanner {
public:
    //右足と左足の初期化
    FootStepPlanner(const Footstep& initial_right_foot, const Footstep& initial_left_foot);
    
    //外部からの歩行パラメータを更新
    void updateWalkParams(const WalkParam& params);

    //数ステップ分の着地位置を記録
    const std::deque<Footstep>& getplan();

    //一歩が完了し次のステップに進む
    void advance();

private:
    //次の一歩の着地位置を計算
    void generateNextStep();

    std::deque<Footstep> plan_;       //未来の数ステップ分の着地位置を記録
    Footstep current_support_foot_;   //現在の着地位置
    Footstep::Leg next_swing_leg_;    //次に動かす足の記録
    Walkparam current_walk_params_;   //歩行パラメータの記録

    int plan_length_ = 5;             //何歩分の着地位置を記録するかの設定
    double default_step_width_ = 0.2; //左右の歩幅
};

}
