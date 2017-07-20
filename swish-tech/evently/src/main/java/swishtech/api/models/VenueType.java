package swishtech.api.models;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;

@Entity
@Table(name="venue_type")
public class VenueType
{
	@Id
	@GeneratedValue(strategy=GenerationType.AUTO)
	private long TypeId;
	
	@NotNull
	private String name;
	
	@NotNull
	private String description;
	
	public VenueType(){}
	
	public VenueType(String name, String description)
	{
		this.name = name;
		this.description = description;
	}

	public long getTypeId()
	{
		return TypeId;
	}

	public void setTypeId(long typeId)
	{
		TypeId = typeId;
	}

	public String getName()
	{
		return name;
	}

	public void setName(String name)
	{
		this.name = name;
	}

	public String getDescription()
	{
		return description;
	}

	public void setDescription(String description)
	{
		this.description = description;
	}
	
}