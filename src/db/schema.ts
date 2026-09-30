import Dexie, { type EntityTable } from "dexie";
import { type Spell } from "@db/types";

const db = new Dexie('db') as Dexie & {
    spells: EntityTable<Spell, 'id'>
};

db.version(1).stores({
    spells: '++id'
});

db.open().catch(() => {
    console.log("Failed to open Dexie Database.")
});

export { db }