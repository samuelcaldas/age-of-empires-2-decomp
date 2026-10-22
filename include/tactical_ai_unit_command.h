#ifndef TACTICAL_AI_UNIT_COMMAND_H
#define TACTICAL_AI_UNIT_COMMAND_H

struct Diplomacy {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual int IsEnemyWith(int player_id);  // slot 8 (offset 32 = 0x20)
    virtual int IsAlliedWith(int player_id); // slot 9 (offset 36 = 0x24)
};

struct Player {
    char pad00[2976];
    int m_player_id; // 2976 (0xBA0)
    char padBA4[3980];
    Diplomacy *m_diplomacy; // 6960 (0x1B30)
};

struct ActionDesc {
    char pad00[6];
    short m_type; // offset 6
    short m_mode; // offset 8
};

struct Manager {
    char pad00[4];
    ActionDesc **m_actions; // offset 4
    short m_action_count;   // offset 8
};

struct UnitTypeInfo {
    char pad00[8];
    short m_type_id;  // offset 8
    char pad0A[4];
    short m_category; // offset 14 (0x0E)
    char pad10[408];
    unsigned char m_class_flags; // offset 424 (0x1A8)
};

struct Unit {
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual void vfn_4();
    virtual void vfn_5();
    virtual void vfn_6();
    virtual void vfn_7();
    virtual void vfn_8();
    virtual void vfn_9();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    virtual void vfn_37();
    virtual void vfn_38();
    virtual void vfn_39();
    virtual void vfn_40();
    virtual void vfn_41();
    virtual void vfn_42();
    virtual void vfn_43();
    virtual void vfn_44();
    virtual void vfn_45();
    virtual void vfn_46();
    virtual void vfn_47();
    virtual void vfn_48();
    virtual void vfn_49();
    virtual void vfn_50();
    virtual void vfn_51();
    virtual void vfn_52();
    // Slot 53: (8 + 53 * 4 = 220 = 0xDC)
    virtual void *GetActionTarget();

    virtual void vfn_54();
    virtual void vfn_55();
    virtual void vfn_56();
    virtual void vfn_57();
    virtual void vfn_58();
    virtual void vfn_59();
    virtual void vfn_60();
    virtual void vfn_61();
    virtual void vfn_62();
    virtual void vfn_63();
    virtual void vfn_64();
    virtual void vfn_65();
    virtual void vfn_66();
    virtual void vfn_67();
    virtual void vfn_68();
    virtual void vfn_69();
    virtual void vfn_70();
    virtual void vfn_71();
    virtual void vfn_72();
    virtual void vfn_73();
    virtual void vfn_74();
    virtual void vfn_75();
    virtual void vfn_76();
    virtual void vfn_77();
    virtual void vfn_78();
    virtual void vfn_79();
    virtual void vfn_80();
    virtual void vfn_81();
    virtual void vfn_82();
    virtual void vfn_83();
    virtual void vfn_84();
    virtual void vfn_85();
    virtual void vfn_86();
    virtual void vfn_87();
    virtual void vfn_88();
    virtual void vfn_89();
    virtual void vfn_90();
    virtual void vfn_91();
    virtual void vfn_92();
    virtual void vfn_93();
    virtual void vfn_94();
    virtual void vfn_95();
    virtual void vfn_96();
    virtual void vfn_97();
    virtual void vfn_98();
    virtual void vfn_99();
    virtual void vfn_100();
    virtual void vfn_101();
    virtual void vfn_102();
    virtual void vfn_103();
    virtual void vfn_104();
    virtual void vfn_105();
    virtual void vfn_106();
    virtual void vfn_107();
    virtual void vfn_108();
    virtual void vfn_109();
    virtual void vfn_110();
    virtual void vfn_111();
    virtual void vfn_112();
    virtual void vfn_113();
    virtual void vfn_114();
    virtual void vfn_115();
    virtual void vfn_116();
    virtual void vfn_117();
    virtual void vfn_118();
    virtual void vfn_119();
    virtual void vfn_120();
    virtual void vfn_121();
    virtual void vfn_122();
    virtual void vfn_123();
    virtual void vfn_124();
    virtual void vfn_125();
    virtual void vfn_126();
    virtual void vfn_127();
    virtual void vfn_128();
    virtual void vfn_129();
    virtual void vfn_130();
    virtual void vfn_131();
    virtual void vfn_132();
    virtual void vfn_133();
    virtual void vfn_134();
    virtual void vfn_135();
    virtual void vfn_136();
    virtual void vfn_137();
    virtual void vfn_138();
    virtual void vfn_139();
    virtual void vfn_140();
    virtual void vfn_141();
    virtual void vfn_142();
    virtual void vfn_143();
    virtual void vfn_144();
    virtual void vfn_145();
    virtual void vfn_146();
    virtual void vfn_147();
    virtual void vfn_148();
    virtual void vfn_149();
    virtual void vfn_150();
    virtual void vfn_151();
    virtual void vfn_152();
    virtual void vfn_153();
    virtual void vfn_154();
    virtual void vfn_155();
    virtual void vfn_156();
    virtual void vfn_157();
    virtual void vfn_158();
    virtual void vfn_159();
    virtual void vfn_160();
    virtual void vfn_161();
    virtual void vfn_162();
    virtual void vfn_163();
    virtual void vfn_164();
    virtual void vfn_165();
    virtual void vfn_166();
    virtual void vfn_167();
    virtual void vfn_168();
    virtual void vfn_169();
    virtual void vfn_170();
    virtual void vfn_171();
    virtual void vfn_172();
    virtual void vfn_173();
    virtual void vfn_174();
    virtual void vfn_175();
    virtual void vfn_176();
    virtual void vfn_177();
    virtual void vfn_178();
    virtual void vfn_179();
    virtual void vfn_180();
    virtual void vfn_181();
    virtual void vfn_182();
    virtual void vfn_183();
    virtual void vfn_184();
    virtual void vfn_185();
    virtual void vfn_186();
    virtual void vfn_187();
    virtual void vfn_188();
    virtual void vfn_189();
    virtual void vfn_190();
    virtual void vfn_191();
    virtual void vfn_192();
    virtual void vfn_193();
    virtual void vfn_194();
    virtual void vfn_195();
    virtual void vfn_196();
    virtual void vfn_197();
    virtual void vfn_198();
    virtual void vfn_199();
    virtual void vfn_200();
    virtual void vfn_201();
    virtual void vfn_202();
    virtual void vfn_203();
    virtual void vfn_204();
    virtual void vfn_205();
    virtual void vfn_206();
    virtual void vfn_207();
    virtual void vfn_208();
    virtual void vfn_209();
    virtual void vfn_210();
    virtual void vfn_211();
    virtual void vfn_212();
    virtual void vfn_213();
    virtual void vfn_214();
    virtual void vfn_215();
    virtual void vfn_216();
    // Slot 217: (8 + 217 * 4 = 876 = 0x36C)
    virtual void GetTargetBoundingBox(short *min_x, short *min_y, short *min_z, int arg4, int arg5);

    UnitTypeInfo *m_type_info; // offset 4
    Player *m_player;          // offset 8
    char pad0C[45];
    unsigned char m_field39;   // offset 57 (0x39)
    unsigned char m_field3A;   // offset 58 (0x3A)
    char pad3B[2];
    short m_field3C;           // offset 60 (0x3C)
    char pad3E[242];
    Unit *m_formation_leader;  // offset 304 (0x130)
};

extern "C" {
    int func_2cc2a0(void *self, void *source, const char *cmd, void *target, short mode, int flag, float x, float y, float z);

    /**
     * Tactical AI Unit Command & Combat Action Coordinator.
     * VRAM: 0x305F30 - 0x307160 (4,656 bytes / 1,164 instructions).
     */
    int func_00305F30(void *self, Unit *source_unit, const char *cmd, Unit *target_unit, short mode, int flag, float x, float y, float z);
}

#endif // TACTICAL_AI_UNIT_COMMAND_H
