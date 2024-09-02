import { writable, type Writable } from "svelte/store";
import { type CharacterData } from "@lib/types";

export const character_data: Writable<CharacterData> = writable({
    // Metadata
    name: "John Doe",
    race: "Human",
    class: "Bard",
    level: 1,

    // Combat Data
    health: 0,
    temp_health: 0,
    max_health: 0,
    armor_class: 0,
    initiative: 0,
    speed: 0,

    // Stats
    strength: 1,
    dexterity: 1,
    constitution: 1,
    intelligence: 1,
    wisdom: 1,
    charisma: 1,

    // Spells
    spells: [
        { level: '1st', current_slots: 1, max_slots: 1, spells: [
            {name: "Temp Spell 1", description: "Temporary description 1.", prepared: true},
            {name: "Temp Spell 2", description: "Temporary description 2.", prepared: true},
            {name: "Temp Spell 3", description: "Temporary description 3.", prepared: false},
            {name: "Temp Spell 4", description: "Temporary description 4.", prepared: false},
        ]},
        
        { level: '2nd', current_slots: 2, max_slots: 2, spells: [
            {name: "Temp Spell 1", description: "Temporary description 1.", prepared: false},
            {name: "Temp Spell 2", description: "Temporary description 2.", prepared: true},
            {name: "Temp Spell 3", description: "Temporary description 3.", prepared: false},
            {name: "Temp Spell 4", description: "Temporary description 4.", prepared: false},
        ]},
        
        { level: '3rd', current_slots: 3, max_slots: 3, spells: [
            {name: "Temp Spell 1", description: "Temporary description 1.", prepared: false},
            {name: "Temp Spell 2", description: "Temporary description 2.", prepared: true},
            {name: "Temp Spell 3", description: "Temporary description 3.", prepared: true},
            {name: "Temp Spell 4", description: "Temporary description 4.", prepared: false},
        ]},
        
        { level: '4th', current_slots: 4, max_slots: 4, spells: [
            {name: "Temp Spell 1", description: "Temporary description 1.", prepared: false},
            {name: "Temp Spell 2", description: "Temporary description 2.", prepared: false},
            {name: "Temp Spell 3", description: "Temporary description 3.", prepared: true},
            {name: "Temp Spell 4", description: "Temporary description 4.", prepared: false},
        ]},
        
        { level: '5th', current_slots: 5, max_slots: 5, spells: [
            {name: "Temp Spell 1", description: "Temporary description 1.", prepared: false},
            {name: "Temp Spell 2", description: "Temporary description 2.", prepared: false},
            {name: "Temp Spell 3", description: "Temporary description 3.", prepared: true},
            {name: "Temp Spell 4", description: "Temporary description 4.", prepared: true},
        ]},
        
        { level: '6th', current_slots: 6, max_slots: 6, spells: [
            {name: "Temp Spell 1", description: "Temporary description 1.", prepared: false},
            {name: "Temp Spell 2", description: "Temporary description 2.", prepared: false},
            {name: "Temp Spell 3", description: "Temporary description 3.", prepared: false},
            {name: "Temp Spell 4", description: "Temporary description 4.", prepared: true},
        ]},
        
        { level: '7th', current_slots: 7, max_slots: 7, spells: [
            {name: "Temp Spell 1", description: "Temporary description 1.", prepared: true},
            {name: "Temp Spell 2", description: "Temporary description 2.", prepared: true},
            {name: "Temp Spell 3", description: "Temporary description 3.", prepared: false},
            {name: "Temp Spell 4", description: "Temporary description 4.", prepared: false},
        ]},
        
        { level: '8th', current_slots: 8, max_slots: 8, spells: [
            {name: "Temp Spell 1", description: "Temporary description 1.", prepared: false},
            {name: "Temp Spell 2", description: "Temporary description 2.", prepared: true},
            {name: "Temp Spell 3", description: "Temporary description 3.", prepared: true},
            {name: "Temp Spell 4", description: "Temporary description 4.", prepared: false},
        ]},
        
        { level: '9th', current_slots: 9, max_slots: 9, spells: [
            {name: "Temp Spell 1", description: "Temporary description 1.", prepared: false},
            {name: "Temp Spell 2", description: "Temporary description 2.", prepared: false},
            {name: "Temp Spell 3", description: "Temporary description 3.", prepared: true},
            {name: "Temp Spell 4", description: "Temporary description 4.", prepared: true},
        ]},
    ],
});