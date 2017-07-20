package swishtech.api.models;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;

@Entity
@Table(name="venue")
public class Venue
{
	@Id
	@GeneratedValue(strategy=GenerationType.AUTO)
	private long venueId;

	@NotNull
	private long typeId;
	
	@NotNull
	private String name;
	
	@NotNull
	private String location;
	
	@NotNull
	private long capacity;
	
	@NotNull
	private String description;
	
	@NotNull
	private long eventId;

	public Venue(){}
	
	public Venue(long typeId, String name, String location, long capacity, String description, long eventId)
	{
		this.typeId = typeId;
		this.name = name;
		this.location = location;
		this.capacity = capacity;
		this.description = description;
		this.eventId = eventId;
	}

	public long getVenueId()
	{
		return venueId;
	}

	public void setVenueId(long venueId)
	{
		this.venueId = venueId;
	}

	public long getTypeId()
	{
		return typeId;
	}

	public void setTypeId(long typeId)
	{
		this.typeId = typeId;
	}

	public String getName()
	{
		return name;
	}

	public void setName(String name)
	{
		this.name = name;
	}

	public String getLocation()
	{
		return location;
	}

	public void setLocation(String location)
	{
		this.location = location;
	}

	public long getCapacity()
	{
		return capacity;
	}

	public void setCapacity(long capacity)
	{
		this.capacity = capacity;
	}

	public String getDescription()
	{
		return description;
	}

	public void setDescription(String description)
	{
		this.description = description;
	}

	public long getEventId()
	{
		return eventId;
	}

	public void setEventId(long eventId)
	{
		this.eventId = eventId;
	}
	
}