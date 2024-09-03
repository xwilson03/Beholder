import Dexie, { type EntityTable } from "dexie";
import { type Spell } from "@db/types";

const db = new Dexie('db') as Dexie & {
    spells: EntityTable<Spell, 'id'>
};

db.version(1).stores({
    spells: '++id'
});

export { db }