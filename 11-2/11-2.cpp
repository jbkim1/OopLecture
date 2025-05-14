#include <iostream>

// ������������ 1�ܰ�: �⺻ Ŭ���� ������������
class Effect
{
protected:
    int level;
public:
    Effect(int lv = 0) : level(lv)
    {
        std::cout << "Effect ����\n";
    }

    virtual ~Effect()
    {
        std::cout << "Effect �Ҹ�\n";
    }

    // ��� �Ļ� Ŭ������ �������� �Լ�
    virtual float Process(float sample)
    {
        std::cout << "Effect::Process " << sample << " �� " << sample << '\n';
        return sample;            // �ƹ� ���� ����
    }
};

// ������������ 2�ܰ��: Filter ������������
class Filter : public Effect
{
    int cutoff;
public:
    Filter(int ct) : Effect(), cutoff(ct)
    {
        std::cout << "Filter ���� (cutoff " << cutoff << ")\n";
    }

    ~Filter() override
    {
        std::cout << "Filter �Ҹ�\n";
    }

    float Process(float sample) override
    {
        float out = sample;
        if (out > cutoff) out = static_cast<float>(cutoff);
        if (out < -cutoff) out = static_cast<float>(-cutoff);

        std::cout << "Filter::Process " << sample << " �� " << out << '\n';
        return out;
    }
};

// ������������ 2�ܰ��: Distortion (�߰� �ܰ�) ������������
class Distortion : public Effect
{
protected:
    int drive;
public:
    Distortion(int dv) : Effect(), drive(dv)
    {
        std::cout << "Distortion ���� (drive " << drive << ")\n";
    }

    ~Distortion() override
    {
        std::cout << "Distortion �Ҹ�\n";
    }

    float Process(float sample) override
    {
        float out = sample;
        if (out > drive) out = static_cast<float>(drive);
        if (out < -drive) out = static_cast<float>(-drive);

        std::cout << "Distortion::Process " << sample << " �� " << out << '\n';
        return out;
    }
};

// ������������ 3�ܰ�: HardDistortion (Distortion �Ļ�) ������������
class HardDistortion : public Distortion
{
public:
    HardDistortion(int dv) : Distortion(dv)
    {
        std::cout << "HardDistortion ���� (drive " << drive << ")\n";
    }

    ~HardDistortion() override
    {
        std::cout << "HardDistortion �Ҹ�\n";
    }

    float Process(float sample) override
    {
        float amplified = sample * 2.0f;            // ���� ����
        float out = amplified;

        if (out > drive) out = static_cast<float>(drive);
        if (out < -drive) out = static_cast<float>(-drive);

        std::cout << "HardDistortion::Process " << sample << " �� " << out << '\n';
        return out;
    }
};

// ������������ �׽�Ʈ �ڵ� ������������
int main()
{
    Effect* chain[4];
    chain[0] = new Effect();
    chain[1] = new Filter(5);           // ��5 Ŭ����
    chain[2] = new Distortion(3);       // ��3 Ŭ����
    chain[3] = new HardDistortion(2);   // ��2 Ŭ���� (2�� ���� ��)

    std::cout << "=== ���� ó�� ���� ===\n";
    float sample = 4.0f;                // �ʱ� �Է� ����
    for (int i = 0; i < 4; ++i)
    {
        sample = chain[i]->Process(sample);
    }

    std::cout << "=== �޸� ���� ===\n";
    for (int i = 3; i >= 0; --i)
    {
        delete chain[i];
    }
    return 0;
}
