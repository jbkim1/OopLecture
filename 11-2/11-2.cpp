#include <iostream>

// ────── 1단계: 기본 클래스 ──────
class Effect
{
protected:
    int level;
public:
    Effect(int lv = 0) : level(lv)
    {
        std::cout << "Effect 생성\n";
    }

    virtual ~Effect()
    {
        std::cout << "Effect 소멸\n";
    }

    // 모든 파생 클래스가 재정의할 함수
    virtual float Process(float sample)
    {
        std::cout << "Effect::Process " << sample << " → " << sample << '\n';
        return sample;            // 아무 변형 없음
    }
};

// ────── 2단계①: Filter ──────
class Filter : public Effect
{
    int cutoff;
public:
    Filter(int ct) : Effect(), cutoff(ct)
    {
        std::cout << "Filter 생성 (cutoff " << cutoff << ")\n";
    }

    ~Filter() override
    {
        std::cout << "Filter 소멸\n";
    }

    float Process(float sample) override
    {
        float out = sample;
        if (out > cutoff) out = static_cast<float>(cutoff);
        if (out < -cutoff) out = static_cast<float>(-cutoff);

        std::cout << "Filter::Process " << sample << " → " << out << '\n';
        return out;
    }
};

// ────── 2단계②: Distortion (중간 단계) ──────
class Distortion : public Effect
{
protected:
    int drive;
public:
    Distortion(int dv) : Effect(), drive(dv)
    {
        std::cout << "Distortion 생성 (drive " << drive << ")\n";
    }

    ~Distortion() override
    {
        std::cout << "Distortion 소멸\n";
    }

    float Process(float sample) override
    {
        float out = sample;
        if (out > drive) out = static_cast<float>(drive);
        if (out < -drive) out = static_cast<float>(-drive);

        std::cout << "Distortion::Process " << sample << " → " << out << '\n';
        return out;
    }
};

// ────── 3단계: HardDistortion (Distortion 파생) ──────
class HardDistortion : public Distortion
{
public:
    HardDistortion(int dv) : Distortion(dv)
    {
        std::cout << "HardDistortion 생성 (drive " << drive << ")\n";
    }

    ~HardDistortion() override
    {
        std::cout << "HardDistortion 소멸\n";
    }

    float Process(float sample) override
    {
        float amplified = sample * 2.0f;            // 강한 증폭
        float out = amplified;

        if (out > drive) out = static_cast<float>(drive);
        if (out < -drive) out = static_cast<float>(-drive);

        std::cout << "HardDistortion::Process " << sample << " → " << out << '\n';
        return out;
    }
};

// ────── 테스트 코드 ──────
int main()
{
    Effect* chain[4];
    chain[0] = new Effect();
    chain[1] = new Filter(5);           // ±5 클리핑
    chain[2] = new Distortion(3);       // ±3 클리핑
    chain[3] = new HardDistortion(2);   // ±2 클리핑 (2배 증폭 후)

    std::cout << "=== 사운드 처리 시작 ===\n";
    float sample = 4.0f;                // 초기 입력 샘플
    for (int i = 0; i < 4; ++i)
    {
        sample = chain[i]->Process(sample);
    }

    std::cout << "=== 메모리 해제 ===\n";
    for (int i = 3; i >= 0; --i)
    {
        delete chain[i];
    }
    return 0;
}
