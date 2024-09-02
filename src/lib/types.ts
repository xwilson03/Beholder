export interface SpellList {
    level: string,
    current_slots: number
    max_slots: number,
    spells: {
        name: string,
        description: string,
        prepared: boolean
    }[]
}

export interface CharacterData {
    // Metadata
    name: string
    race: string
    class: string
    level: number

    // Combat Data
    health: number
    temp_health: number
    max_health: number
    armor_class: number
    initiative: number
    speed: number

    // Stats
    strength: number
    dexterity: number
    constitution: number
    intelligence: number
    wisdom: number
    charisma: number

    // Spells
    spells: SpellList[]
};